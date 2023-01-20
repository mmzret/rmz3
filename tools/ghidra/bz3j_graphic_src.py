# Add EOL Comment on Graphic src property.
# @author   Pokemium (2022-06-05)
# @category BZ3J

from ghidra.program.model.data import ArrayDataType

dtm = currentProgram.getDataTypeManager()

a = dtm.getLocalSourceArchive()

after = 0x085d80f1


def get_byte(addr):
    def u8(val):
        if val < 0:
            val += 256
        return val
    b = getByte(toAddr(addr))
    return u8(b)


def datatype(typename):
    for dt in dtm.getDataTypes(a):
        if dt.getName() == typename:
            return dt
    return None


U8 = datatype("u8")
Pltt = datatype("PlttData")


def get_arraytype(t, num, length):
    a = ArrayDataType(t, num, length)
    return a


def get_pltt_arr(length):
    return get_arraytype(Pltt, length, 2)


def set_datatype(addr, dt):
    """
    set DataType into addr
    ```py
    set_datatype(0x0202fe27, datatype("u8"))
    ```
    """
    clearListing(addr, addr.add(dt.getLength()))
    createData(addr, dt)


def get_all_data(after):
    d = getDataAfter(toAddr(after))
    while d is not None:
        yield d
        d = getDataAfter(d)


def u8(val):
    if val < 0:
        val += 256
    return val


def get_word(addr):
    arr = getBytes(toAddr(addr), 4)
    b0 = u8(arr[0])
    b1 = u8(arr[1])
    b2 = u8(arr[2])
    b3 = u8(arr[3])
    return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24)


def get_hword(addr):
    arr = getBytes(toAddr(addr), 2)
    b0 = u8(arr[0])
    b1 = u8(arr[1])
    return b0 | (b1 << 8)


def toInt(addr):
    return int("0x{}".format(addr), 16)


def parse_graphic(addr):
    ofs = get_word(toInt(addr))
    size = get_hword(toInt(addr)+4)
    if size == 0:
        return False
    palsize = get_hword(toInt(addr)+16)
    src = addr.add(ofs)
    magic = get_byte(toInt(src))
    if magic == 0x10:
        return False
    palSrc = src.add(size)
    print("Graphic: 0x{}, Src: 0x{} Size: {} Palette: 0x{}, PalByteSize/2: {}".format(addr,
                                                                                      src, size, palSrc, palsize/2))
    if size > 0:
        arr = get_arraytype(U8, size, size)
        set_datatype(src, arr)
    if palsize > 0:
        set_datatype(palSrc, get_pltt_arr(palsize/2))
    return True


def main():
    count = 0
    max = 10

    ds = get_all_data(after)
    for d in ds:
        if max > 0 and count >= max:
            return
        addr = d.getAddress()
        dt = d.getDataType()
        typename = dt.getName()

        if typename == "Graphic":
            if parse_graphic(addr):
                count += 1
        elif typename.startswith("Graphic["):
            length = int(typename[8:-1])
            for i in range(length):
                if parse_graphic(addr.add(20*i)):
                    count += 1

        else:
            continue


if __name__ == "__main__":
    main()

# Calc Text addr from TextID.
# @author   Pokemium (2022-06-05)
# @category BZ3J

def main():
    val = askInt("TextID", "Enter: ")
    hi = (val >> 8) & 0xff
    lo = (val & 0xff)
    table = get_word(0x08376808 + hi*4)
    ofss = get_word(0x083767b8+hi*4)  # u16[]
    ofs = get_hword(ofss+lo*2)
    print(toAddr(table+ofs))
    return


def get_hword(addr):
    """
    addr is int or str.
    ```
        h = get_hword(0x08037058)
    ```
    """
    arr = getBytes(toAddr(addr), 2)
    b0 = u8(arr[0])
    b1 = u8(arr[1])
    return b0 | (b1 << 8)


def get_word(addr):
    """
    addr is int or str.
    ```
        w = get_word(0x08037058)
    ```
    """
    arr = getBytes(toAddr(addr), 4)
    b0 = u8(arr[0])
    b1 = u8(arr[1])
    b2 = u8(arr[2])
    b3 = u8(arr[3])
    return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24)


def u8(val):
    if val < 0:
        val += 256
    return val


if __name__ == "__main__":
    main()

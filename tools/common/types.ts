export type GraphicProp = '4bpp' | '8bpp' | 'lz77' | 'no_pal' | 'chunked';

// e.g. sprites/dynamic/anubis/header.json の data の要素
export type GraphicHeader = {
  name: string; // ".png" | ".4bpp" | ".lz"
  ofs: number;
  chunkSize: number;
  props: GraphicProp[];
  palette?: {
    color: number;
    id: number;
  };
  files?: string[];
  hdrOnly?: boolean;
};

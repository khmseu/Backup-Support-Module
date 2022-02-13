/// <reference types="node" />
export declare function getpwuid(user: number): {
    name: string;
    uid: number;
    gid: number;
    dir: string;
    shell: string;
};
export declare function getgrgid(group: number): {
    name: string;
    gid: number;
    mem: Array<string>;
};
declare const isBZFILE: unique symbol;
declare type BZFILE = {
    [isBZFILE]: true;
};
export declare function BZ2_bzWriteOpen(f: number): {
    bzf: BZFILE;
    bz2err: number;
    bz2errstr: string;
    syserrno?: number;
    syserrstr?: string;
};
export declare function BZ2_bzWrite(b: BZFILE, buf: Buffer): {
    bzf: BZFILE;
    bz2err: number;
    bz2errstr: string;
    syserrno?: number;
    syserrstr?: string;
};
export declare function BZ2_bzWriteClose(b: BZFILE): {
    bzf: BZFILE;
    bz2err: number;
    bz2errstr: string;
    syserrno?: number;
    syserrstr?: string;
    nbytes_in: number;
    nbytes_out: number;
};
export {};

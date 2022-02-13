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

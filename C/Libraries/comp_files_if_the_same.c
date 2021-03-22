/*
struct stat src, dst;
int err;
err = stat(src_file, &src);
if (err < 0) {
    perror("stat");
    exit(1);
}
err = stat(dst_file, &dst);
if (err < 0) {
    perror("stat");
    exit(1);
}
if ((src.st_dev == dst.st_dev) && (src.st_ino == dst.st_ino)) { // This checks if the files are the same
    // same file, skip copy
}
// copy the file
*/
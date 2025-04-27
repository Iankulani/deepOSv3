#include "disk.h"

struct ext2_superblock {
    uint32_t inodes_count;
    uint32_t blocks_count;
    // ... (other fields)
};

void read_superblock(int disk_fd, struct ext2_superblock* sb) {
    lseek(disk_fd, 1024, SEEK_SET); // Superblock at offset 1024
    read(disk_fd, sb, sizeof(struct ext2_superblock));
}

int mount_ext2(const char* device) {
    int fd = open(device, O_RDONLY);
    struct ext2_superblock sb;
    read_superblock(fd, &sb);
    
    if (sb.magic != 0xEF53) {
        printf("Invalid EXT2 Filesystem\n");
        return -1;
    }
    
    printf("EXT2 Mounted: %s\n", device);
    return fd;
}
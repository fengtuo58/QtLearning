/* Generated by configure */
#include <poll.h>
int main(int argc, char **argv)
{
    (void)argc; (void)argv;
    /* BEGIN TEST: */
    struct pollfd pfd;
    poll(&pfd, 1, 0);
    /* END TEST */
    return 0;
}
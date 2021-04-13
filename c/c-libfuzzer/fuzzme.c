#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int fuzzme(char *buf, unsigned len)
{
  if(buf[0] == 'b')
    if(buf[1] == 'u')
      if(buf[2] == 'g') {
        printf("You've got it!");
        return 1/0;      // Defect: divide-by-zero.
      }
  return 0;
}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
  fuzzme((char *) Data, Size);
  return 0;
}
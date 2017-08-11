/* Memory pool and allocation routines */

#define MEM_POOL_SIZE 1024
#define MEM_CHUNK_SIZE 16
#define MEM_CHUNKS_NUM (MEM_POOL_SIZE/MEM_CHUNK_SIZE)

static unsigned char pool[MEM_POOL_SIZE];
static unsigned char mem_idx[MEM_CHUNKS_NUM];

unsigned char *
mem_alloc(unsigned int size)
{
  unsigned char *mem = 0;
  int i;
  unsigned int s, r, chunks;

  /* calculate total amount of memory in chunks */
  s = size / MEM_CHUNK_SIZE;
  r = size % MEM_CHUNK_SIZE;
  if (r)
    s++;

  chunks = 0;
  for (i = 0; i < MEM_CHUNKS_NUM; i++) {
    if (mem_idx[i]) {
      mem = 0;
      chunks = 0;
      continue;
    }

    if (chunks == 0)
      mem = &pool[i * MEM_CHUNK_SIZE];
    chunks++;

    if (chunks == s)
      return mem;
  }

  return 0;
}

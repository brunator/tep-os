/* Memory pool and allocation routines */

#define MEM_POOL_SIZE 1024
#define MEM_CHUNK_SIZE 16
#define MEM_CHUNKS_NUM (MEM_POOL_SIZE/MEM_CHUNK_SIZE)

static unsigned char pool[MEM_POOL_SIZE];
static unsigned char mem_idx[MEM_CHUNKS_NUM];

void *
mem_alloc(unsigned int size)
{
  unsigned char *mem = 0;
  int i, tmp;
  unsigned int s, r, chunks;

  /* calculate total amount of memory in chunks */
  s = size / MEM_CHUNK_SIZE;
  r = size % MEM_CHUNK_SIZE;
  if (r)
    s++;

  chunks = 0;
  for (i = 0; i < MEM_CHUNKS_NUM; i++) {
    if (mem_idx[i] > 0) {
      mem = 0;
      chunks = 0;
      continue;
    }

    if (chunks == 0) {
      mem = &pool[i * MEM_CHUNK_SIZE];
      tmp = i;
    }
    chunks++;

    if (chunks == s) {
      mem_idx[tmp] = chunks;
      return mem;
    }
  }

  return 0;
}

void
mem_free(void *ptr)
{
  unsigned int tmp = (unsigned int)(ptr - (void *)pool);
  int i, pi = tmp/MEM_CHUNK_SIZE;

  if (pi >= MEM_CHUNKS_NUM)
    return;

  for (i = 0; i < mem_idx[pi]; i++)
    mem_idx[pi + i] = 0;
}


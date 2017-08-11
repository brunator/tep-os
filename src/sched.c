/* An attempt to write MLFQ scheduler simulator */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define BOOST_PERIOD 50 /* miliseconds */
#define PRIOR_QUEUES 3
#define CLOCK_TICK 1
#define TIME_SLICE 10
#define MAX_SIMULATION_TIME 1000

#define TICK_INIT(t) do { t = 0; } while (0)
#define TICK(t) do { \
    t += CLOCK_TICK; \
    if (t >= MAX_SIMULATION_TIME) { \
      printf("[time %u] SIMULATION HAS ENDED\n", t); \
      exit(0); \
    } \
  } while (0)

typedef struct task_list task_list_t;
struct task_list {
  unsigned int time_consumed;
  unsigned char io_pending;
  task_list_t *next_task;
};

typedef struct prior_queue {
  unsigned int quantum;
  task_list_t *task_list;
} prior_queue_t;

prior_queue_t prior_queues[PRIOR_QUEUES];

void
init_prior_queue(void)
{
  int i;

  for (i = 0; i < PRIOR_QUEUES; i++);
}

int
main(int argc, char *argv[])
{
  unsigned int gc; /* global tick */

  TICK_INIT(gc);
  init_prior_queue();

  while (1) {
    TICK(gc);
  }

  return 0;
}

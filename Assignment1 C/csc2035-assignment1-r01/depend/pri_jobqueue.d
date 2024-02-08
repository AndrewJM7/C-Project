objects/pri_jobqueue.o: pri_jobqueue.c pri_jobqueue.h sim_config.h job.h | objects
	$(CC) -c $(CFLAGS) $< -o $@

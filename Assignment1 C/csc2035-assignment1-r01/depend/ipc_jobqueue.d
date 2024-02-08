objects/ipc_jobqueue.o: ipc_jobqueue.c ipc_jobqueue.h pri_jobqueue.h sim_config.h \
  job.h ipc.h proc.h | objects
	$(CC) -c $(CFLAGS) $< -o $@

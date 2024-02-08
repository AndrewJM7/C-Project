objects/test/test_sem_jobqueue.o: test/test_sem_jobqueue.c test/test_jobqueue_common.h \
  test/munit/munit.h test/test_ipc_jobqueue.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@

objects/test/test_pri_jobqueue.o: test/test_pri_jobqueue.c test/test_jobqueue_common.h \
  test/munit/munit.h test/test_pri_jobqueue.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@

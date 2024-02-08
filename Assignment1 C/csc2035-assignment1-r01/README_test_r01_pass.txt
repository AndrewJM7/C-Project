The following is expected test output after correct implementation of the
functions specified in README01.txt. In release 1 all tests of queues simply 
report tests are skipped. That is no tests of queues are provided for release 1.

------------------------------------------------------
Running bin/test/test_ipc ...
Running test suite with seed 0xaa708ad7...
/test_ipc/test_ipc                   [ OK    ] [ 1.00162100 / 0.00034200 CPU ]
/test_ipc/test_ipc_err               [ OK    ] [ 0.00000300 / 0.00000200 CPU ]
2 of 2 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_ipc_jobqueue ...
Running test suite with seed 0xb82c51ea...
/test_ipc_jobqueue/test_ipc_jobqueue_dummy
*******************************************************
Dummy placeholder test to be replaced by complete tests.
*******************************************************
[ SKIP  ]
No tests run, 1 (100%) skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_job ...
Running test suite with seed 0xbc730fd5...
/test_job/test_job_new               [ OK    ] [ 0.00031800 / 0.00031800 CPU ]
/test_job/test_job_new_null          [ OK    ] [ 0.00004800 / 0.00004700 CPU ]
/test_job/test_job_copy_stack        [ OK    ] [ 0.00025100 / 0.00025100 CPU ]
/test_job/test_job_copy_heap         [ OK    ] [ 0.00028600 / 0.00028600 CPU ]
/test_job/test_job_copy_identity     [ OK    ] [ 0.00047700 / 0.00047700 CPU ]
/test_job/test_job_copy_null         [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_job/test_job_init_stack        [ OK    ] [ 0.00026400 / 0.00026400 CPU ]
/test_job/test_job_init_heap         [ OK    ] [ 0.00025400 / 0.00025300 CPU ]
/test_job/test_job_init_null         [ OK    ] [ 0.00000000 / 0.00000100 CPU ]
/test_job/test_job_is_equal          [ OK    ] [ 0.00046100 / 0.00046100 CPU ]
/test_job/test_job_is_equal_init     [ OK    ] [ 0.00003800 / 0.00003800 CPU ]
/test_job/test_job_is_equal_null     [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_job/test_job_set_stack         [ OK    ] [ 0.00023700 / 0.00023600 CPU ]
/test_job/test_job_set_heap          [ OK    ] [ 0.00024300 / 0.00024200 CPU ]
/test_job/test_job_set_null          [ OK    ] [ 0.00002900 / 0.00002900 CPU ]
/test_job/test_job_to_str_stack      [ OK    ] [ 0.00000600 / 0.00000500 CPU ]
/test_job/test_job_to_str_heap       [ OK    ] [ 0.00000600 / 0.00000600 CPU ]
/test_job/test_job_delete            [ OK    ] [ 0.00000000 / 0.00000000 CPU ]
18 of 18 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_joblog ...
Running test suite with seed 0xa6e7c178...
/test_joblog/test_joblog_write_cpid0 [ OK    ] [ 0.00197800 / 0.00079300 CPU ]
/test_joblog/test_joblog_write_cpid1 [ OK    ] [ 0.00054800 / 0.00040800 CPU ]
/test_joblog/test_joblog_write_cpid2 [ OK    ] [ 0.00041700 / 0.00034000 CPU ]
/test_joblog/test_joblog_write_cpid3 [ OK    ] [ 0.00042700 / 0.00037400 CPU ]
/test_joblog/test_joblog_write_errno [ OK    ] [ 0.00036300 / 0.00030600 CPU ]
/test_joblog/test_joblog_write_null  [ OK    ] [ 0.00000200 / 0.00000100 CPU ]
/test_joblog/test_joblog_read_cpid0  [ OK    ] [ 0.00016100 / 0.00015200 CPU ]
/test_joblog/test_joblog_read_cpid1  [ OK    ] [ 0.00019900 / 0.00019500 CPU ]
/test_joblog/test_joblog_read_cpid2  [ OK    ] [ 0.00021100 / 0.00020800 CPU ]
/test_joblog/test_joblog_read_cpid3  [ OK    ] [ 0.00016600 / 0.00015800 CPU ]
/test_joblog/test_joblog_read_stack  [ OK    ] [ 0.00017100 / 0.00016000 CPU ]
/test_joblog/test_joblog_read_rand   [ OK    ] [ 0.00021900 / 0.00021200 CPU ]
/test_joblog/test_joblog_read_errno  [ OK    ] [ 0.00015300 / 0.00015200 CPU ]
/test_joblog/test_joblog_read_bounds [ OK    ] [ 0.00008100 / 0.00007700 CPU ]
/test_joblog/test_joblog_read_null   [ OK    ] [ 0.00000500 / 0.00000500 CPU ]
/test_joblog/test_joblog_delete      [ OK    ] [ 0.00019700 / 0.00019700 CPU ]
16 of 16 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_pri_jobqueue ...
Running test suite with seed 0x616b228e...
/test_pri_jobqueue/test_pri_jobqueue_dummy
*******************************************************
Dummy placeholder test to be replaced by complete tests.
*******************************************************
[ SKIP  ]
No tests run, 1 (100%) skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_proc ...
Running test suite with seed 0xfe6fc645...
/test_util/test_proc_new             [ OK    ] [ 0.00002700 / 0.00002600 CPU ]
/test_util/test_proc_new_null        [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
2 of 2 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_sem_jobqueue ...
Running test suite with seed 0x6d59d2c0...
/test_ipc_jobqueue/test_ipc_jobqueue_dummy
*******************************************************
Dummy placeholder test to be replaced by complete tests.
*******************************************************
[ SKIP  ]
No tests run, 1 (100%) skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_shobject_name ...
Running test suite with seed 0xcb190e67...
/test_shobject_name/test_shobject_name_short[ OK    ] [ 0.00000900 / 0.00000700 CPU ]
/test_shobject_name/test_shobject_name_empty[ OK    ] [ 0.00000400 / 0.00000400 CPU ]
/test_shobject_name/test_shobject_name_char[ OK    ] [ 0.00000200 / 0.00000100 CPU ]
/test_shobject_name/test_shobject_name_long[ OK    ] [ 0.00000200 / 0.00000100 CPU ]
/test_shobject_name/test_shobject_name_null[ OK    ] [ 0.00000100 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_short_heap[ OK    ] [ 0.00000200 / 0.00000000 CPU ]
/test_shobject_name/test_shobject_name_empty_heap[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_shobject_name/test_shobject_name_char_heap[ OK    ] [ 0.00000100 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_long_heap[ OK    ] [ 0.00000100 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_null_heap[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
10 of 10 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------

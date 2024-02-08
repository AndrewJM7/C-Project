The following is expected test output (mostly errors) for the initial 
release of the project before the functions specified in README01.txt are 
implemented. 

Note:
    1. some error messages will differ on different machines.
    2. some tests pass because the initial implementation trivially passes
       a test, for example when NULL is the expected return value from a 
       a function under test. 
    3. In release 1 all tests of queues simply report tests are skipped. 
       That is no tests of queues are provided for release 1.
       
The output you get will be similar to but not necessarily identical to the
following.

------------------------------------------------------
Running bin/test/test_ipc ...
Running test suite with seed 0x23c4d161...
/test_ipc/test_ipc                   [ OK    ] [ 1.00174400 / 0.00037200 CPU ]
/test_ipc/test_ipc_err               [ OK    ] [ 0.00000500 / 0.00000500 CPU ]
2 of 2 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_ipc_jobqueue ...
Running test suite with seed 0xd38cf5a3...
/test_ipc_jobqueue/test_ipc_jobqueue_dummy
*******************************************************
Dummy placeholder test to be replaced by complete tests.
*******************************************************
[ SKIP  ]
No tests run, 1 (100%) skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_job ...
Running test suite with seed 0xc3e1a0dc...
/test_job/test_job_new               [ ERROR ]
Info: test/test_job.c:155: line 156: assert_valid_job call with i: 0
Error: test/test_job.c:134: assertion failed: job->pid == expected_pid (0 == 36745)
Error: child killed by signal 6
/test_job/test_job_new_null          [ ERROR ]
Info: test/test_job.c:170: line 171: assert_valid_job call
Error: test/test_job.c:134: assertion failed: job->pid == expected_pid (0 == 36746)
Error: child killed by signal 6
/test_job/test_job_copy_stack        [ ERROR ]
Error: test/test_job.c:188: assertion failed: cpy == &dst (0x16fb672fc == 0x16fb672d0)
Error: child killed by signal 6
/test_job/test_job_copy_heap         [ ERROR ]
Error: test/test_job.c:211: assertion failed: cpy != &src (0x16fb6730c != 0x16fb6730c)
Error: child killed by signal 6
/test_job/test_job_copy_identity     [ ERROR ]
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 0
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 1
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 2
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 3
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 4
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 5
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 6
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 7
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 8
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 9
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 10
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 11
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 12
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 13
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 14
Info: test/test_job.c:234: line 235: assert_valid_job call with i: 15
Error: test/test_job.c:250: assertion failed: cpy == &eq2src (0x16fb672fc == 0x16fb672d0)
Error: child killed by signal 6
/test_job/test_job_copy_null         [ OK    ] [ 0.00000400 / 0.00000400 CPU ]
/test_job/test_job_init_stack        [ ERROR ]
Info: test/test_job.c:281: line 281: assert_init_job call
Error: test/test_job.c:92: assertion failed: job->id == 0 (1874228032 == 0)
Error: child killed by signal 6
/test_job/test_job_init_heap         [ ERROR ]
Info: test/test_job.c:303: line 303: assert_init_job call
Error: test/test_job.c:96: assertion failed: job->label[i] == '*' ('\x00' == '\x2a')
Error: child killed by signal 6
/test_job/test_job_init_null         [ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_job/test_job_is_equal          [ ERROR ]
Info: test/test_job.c:339: line 340: assert_job_equalities call with i: 0
Error: test/test_job.c:102: assertion failed: job_is_equal(j1, j1) is not true
Error: child killed by signal 6
/test_job/test_job_is_equal_init     [ ERROR ]
Info: test/test_job.c:360: line 361: assert_init_job call with i: 0
Error: test/test_job.c:363: assertion failed: job_is_equal(&j1, &j2) is not true
Error: child killed by signal 6
/test_job/test_job_is_equal_null     [ ERROR ]
Error: test/test_job.c:383: assertion failed: job_is_equal(((void *)0), ((void *)0)) is not true
Error: child killed by signal 6
/test_job/test_job_set_stack         [ ERROR ]
Info: test/test_job.c:406: line 407: assert_valid_job call with i: 0
Error: test/test_job.c:134: assertion failed: job->pid == expected_pid (0 == 36757)
Error: child killed by signal 6
/test_job/test_job_set_heap          [ ERROR ]
Info: test/test_job.c:422: line 423: assert_valid_job call with i: 0
Error: test/test_job.c:134: assertion failed: job->pid == expected_pid (0 == 36758)
Error: child killed by signal 6
/test_job/test_job_set_null          [ ERROR ]
Info: test/test_job.c:441: line 442: assert_valid_job call
Error: test/test_job.c:134: assertion failed: job->pid == expected_pid (0 == 36759)
Error: child killed by signal 6
/test_job/test_job_to_str_stack      [ ERROR ]
Error: child killed by signal 11
/test_job/test_job_to_str_heap       [ ERROR ]
Error: child killed by signal 11
/test_job/test_job_delete            [ OK    ] [ 0.00000100 / 0.00000000 CPU ]
3 of 18 (17%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_joblog ...
Running test suite with seed 0x3bef62c3...
/test_joblog/test_joblog_write_cpid0 [ FAIL  ]
/test_joblog/test_joblog_write_cpid1 [ FAIL  ]
/test_joblog/test_joblog_write_cpid2 [ FAIL  ]
/test_joblog/test_joblog_write_cpid3 [ FAIL  ]
/test_joblog/test_joblog_write_errno [ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_joblog/test_joblog_write_null  [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_joblog/test_joblog_read_cpid0  [ ERROR ]
Error: test/test_joblog.c:184: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_cpid1  [ ERROR ]
Error: test/test_joblog.c:184: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_cpid2  [ ERROR ]
Error: test/test_joblog.c:184: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_cpid3  [ ERROR ]
Error: test/test_joblog.c:184: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_stack  [ ERROR ]
Error: test/test_joblog.c:184: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_rand   [ ERROR ]
Error: child killed by signal 11
/test_joblog/test_joblog_read_errno  [ ERROR ]
Error: test/test_joblog.c:184: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_joblog_read_bounds [ OK    ] [ 0.00005900 / 0.00005900 CPU ]
/test_joblog/test_joblog_read_null   [ OK    ] [ 0.00000000 / 0.00000000 CPU ]
/test_joblog/test_joblog_delete      [ ERROR ]
Error: test/test_joblog.c:438: assertion failed: access(log_fname[i], 0) == -1 (0 == -1)
Error: child killed by signal 6
4 of 16 (25%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_pri_jobqueue ...
Running test suite with seed 0xf35ab64d...
/test_pri_jobqueue/test_pri_jobqueue_dummy
*******************************************************
Dummy placeholder test to be replaced by complete tests.
*******************************************************
[ SKIP  ]
No tests run, 1 (100%) skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_proc ...
Running test suite with seed 0x7a54e273...
/test_util/test_proc_new             [ OK    ] [ 0.00001100 / 0.00001100 CPU ]
/test_util/test_proc_new_null        [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
2 of 2 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_sem_jobqueue ...
Running test suite with seed 0x26b4762a...
/test_ipc_jobqueue/test_ipc_jobqueue_dummy
*******************************************************
Dummy placeholder test to be replaced by complete tests.
*******************************************************
[ SKIP  ]
No tests run, 1 (100%) skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_shobject_name ...
Running test suite with seed 0x6376839e...
/test_shobject_name/test_shobject_name_short[ OK    ] [ 0.00001200 / 0.00001100 CPU ]
/test_shobject_name/test_shobject_name_empty[ OK    ] [ 0.00000400 / 0.00000300 CPU ]
/test_shobject_name/test_shobject_name_char[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_long[ OK    ] [ 0.00000100 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_null[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_shobject_name/test_shobject_name_short_heap[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_empty_heap[ OK    ] [ 0.00000100 / 0.00000000 CPU ]
/test_shobject_name/test_shobject_name_char_heap[ OK    ] [ 0.00000200 / 0.00000200 CPU ]
/test_shobject_name/test_shobject_name_long_heap[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
/test_shobject_name/test_shobject_name_null_heap[ OK    ] [ 0.00000100 / 0.00000100 CPU ]
10 of 10 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------


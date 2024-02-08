README FOR RELEASE 02 OF CSC2035 ASSIGNMENT 1 CODE BASE

This release provides this README file (README02.txt) plus the following:

    job.h - an update to the job.h file to correct an error (see changes 
            section below)
    test - a complete new directory of test files (see changes section 
           below)
           
There is also some additional guidance at the end of this README file.
    
-----------------------------------------------------------------------------

UPDATING YOUR CODE BASE

1. BACKUP YOUR CURRENT CODEBASE BEFORE YOU DO ANYTHING ELSE

2. unzip the csc2035-assignment1-r02.zip archive (or expand the tgz archive)

3. use the cp command to copy the job.h file from the 
   csc2035-assignment1-r02 directory to your current project directory
   (csc2035-assignment1-r01, unless you have changed the name)

4. update the test directory of your current project directory by doing
   the following:
   
   In the current project directory use the following command:
        rm -rf ./test
   to remove your existing test directory
   
   Then, in the new csc2035-assignment1-r02 directory, use the 
   following command:
        cp -R ./test <current-project-directory>

   to copy the new test directory to your current project directory 
   (where  <current-project-directory> is replaced by the path to your 
   current project directory)
    
5. In your current project directory, make dependencies with the following 
   commands:
   
   make clean_depend
   make depend
   
   - you only have to do this once.
   
6. Compile and run the tests as follows:

   make clean
   make
   ./runtests.sh
   
It is possible that tests of pri_jobqueue and ipc_jobqueue will
enter infinite loops if parts of the implementations are not correct. If
a test hangs and does not make progress, enter:

    CTRL-c or ^c - control and c together

to terminate the test.

You may also find that tests of sem_jobqueue block. In which case, do the 
same.

You can always run individual tests, as described in README01.txt.
   
-----------------------------------------------------------------------------

CHANGES

1. Changes to job.h

job.h has been updated because there was an error in the example string
representation in the documentation of job_to_str and str_to_job. 

Release 01 of job.h gave the following example string representation:

  "pid:0000001,id:00002,priority:00003,label:newjob*************************"

In release 02, the correct example representation is:

  "pid:0000001,id:00002,pri:00003,label:newjob*************************"
    
where "priority:" becomes "pri:". This is the correct format and is
consistent with the JOB_STR_FORMAT string format and the JOB_STR_SIZE
value.

The release 02 example is also consistent with release 01 and 02 tests
for job.c.

If you are using the JOB_STR_FORMAT and JOB_STR_SIZE symbols in your
code you will not have noticed the above inconsistency.

In addition to the above, the following statement has been removed from
the job_set function documentation:
   If the fields of the job are already equal to the pid, id, priority 
   and label parameters to job_set, this function has no effect.

because it is redundant.


2. Changes to tests

The tests of job.c have been updated and now include tests of the
str_to_job function.

Queue tests (test_ipc_jobqueue, test_pri_jobqueue and sem_jobqueue) have
been added.
   
-----------------------------------------------------------------------------

ADDITIONAL GUIDANCE

- Use C library functions (e.g. for string comparison). Do not invent your
  own.
- Use helper functions that are provided for you (see joblog.c).
- Use constants that are defined for you (e.g. MAX_NAME_SIZE and others).
- Read all the information that is provided in Canvas including:
      o information in the assignment discussion
      o the demonstrations that are listed as relevant to the assignment
        (see summative assessment summary and the assignment guidance page)
      o function documentation in header files
- Look at tests for code that could be useful for your solution and that 
  provide example usage (e.g. manipulating strings and arrays, writing
  to file, etc.).
- Look at the CSC1032 material on C strings, arrays and structs in the 
  PDF file: csc1032-cprogramming-part2.pdf
  This is now also directly available in the CSC2035 Canvas pages.
  
-----------------------------------------------------------------------------

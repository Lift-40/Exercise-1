#Part 3
- What is concurrency? What is parallelism? What's the difference?
 - Concurrency is the property an algorithm has if it can be divided into smaller parts that can be run out of order without changing the result.
 - Parallelism is running multiple things at the same time
 - Concurrency does not imply that multiple operations are happening at the same time; you can have concurrency on a single thread as well.
- Why have machines become increasingly multicore in the past decade?
 - Processor speed has become harder and harder to increase economically, so we’ve simply started adding more processors (cores) instead of attempting to make a single core run faster.
- What kinds of problems motivates the need for concurrent execution? (Or phrased differently: What problems do concurrency help in solving?)
 - Parallelism and speed, mainly - if you have an algorithm is concurrent you may run multiple parts of it at once and then combine the parts afterwards into your result, which may be much faster than running each operation after the other.
- Does creating concurrent programs make the programmer's life easier? Harder? Maybe both? (Come back to this after you have worked on part 4 of this exercise)
 - Harder, mostly.
- What are the differences between processes, threads, green threads, and coroutines?
 - Processes
  - A single program, which may be assigned to one (or multiple) threads.
 - Threads
  - A thread is a single processor, essentially
  - Scheduled natively, i.e. by the host operating system
 - Green threads
  - Scheduled by a VM
 - Coroutines
  - These are subroutines with multiple entry/exit points for flow control, unlike for example traditional functions which has a single entry point and multiple exit points.
  - They are not concurrent, as control is passed between subroutines without more than one ever running at once.
- Which one of these do pthread_create() (C/POSIX), threading.Thread() (Python), go (Go) create?
 - A native thread.
- How does pythons Global Interpreter Lock (GIL) influence the way a python Thread behaves?
 - It prevents the process in question from running on more than a single thread.
- With this in mind: What is the workaround for the GIL (Hint: it's another module)?
 - The Python multiprocess module, for example.
- What does func GOMAXPROCS(n int) int change?
 - The maximum amount of threads that can be used simultaneously.
 - Setting it to 1 obviously removes the race condition.
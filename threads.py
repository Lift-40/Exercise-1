# -*- coding: utf-8 -*-
"""
Created on Wed Jan 18 13:06:48 2017

@author: César Gutiérrez
"""

from threading import Thread

shared_var = 0

def func1():
   count = 0
   global shared_var
   while count < 1000000:
      shared_var += 1
      count += 1
      
      
def func2():
   count = 0
   global shared_var
   while count < 1000000:
      shared_var -= 1
      count += 1

def main():
    global shared_var
    thread1 = Thread(target = func1, args = ())
    thread2 = Thread(target = func2, args = ())
    thread1.start()
    thread2.start()
    
    thread1.join()
    thread2.join()
    
    print "shared_var = %d" % shared_var

main()
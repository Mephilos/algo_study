import threading
import os

def foo():
    pid = os.getpid()
    tid = threading.get_native_id()
    print(f"foo: PID ={pid}, Thread ID = {tid}")

def bar():
    pid = os.getpid()
    tid = threading.get_native_id()
    print(f"bar: PID = {pid}, Thread ID = {tid}")

def baz():
    pid = os.getpid()
    tid = threading.get_native_id()
    print(f"baz: PID = {pid}, Thread ID = {tid}")

if __name__ == "__main__":
    thread1 = threading.Thread(target =foo)
    thread2 = threading.Thread(target =bar)
    thread3 = threading.Thread(target =baz)

    thread1.start()
    thread2.start()
    thread3.start()
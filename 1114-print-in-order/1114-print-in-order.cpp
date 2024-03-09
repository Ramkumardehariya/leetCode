class Foo {
    mutex m;
    condition_variable cv;
    int turn;
public:
    Foo() {
        turn = 0;
    }

    void first(function<void()> printFirst) {
        printFirst();
        turn = 1;
        cv.notify_all();
        
        // printFirst() outputs "first". Do not change or remove this line. 
    }

    void second(function<void()> printSecond) {

        unique_lock<mutex> lock(m);

        while(turn != 1){
            cv.wait(lock);
        }

        printSecond();
        turn = 2;
        cv.notify_all();
        // printSecond() outputs "second". Do not change or remove this line.
        
    }

    void third(function<void()> printThird) {

        unique_lock<mutex> lock(m);

        while(turn != 2){
            cv.wait(lock);
        }

        printThird();
        // turn = 1;
        // cv.notify_all();
        
        // printThird() outputs "third". Do not change or remove this line.
        
    }
};
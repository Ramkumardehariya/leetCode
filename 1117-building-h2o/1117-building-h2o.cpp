class H2O {
    int turn;
    mutex m;
    condition_variable cv;
public:
    H2O() {
        turn = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
            unique_lock<mutex> lock(m);
            while(turn == 2){
                cv.wait(lock);
            }

            releaseHydrogen();
            turn++;
            cv.notify_all();
       
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
    }

    void oxygen(function<void()> releaseOxygen) {
        
            unique_lock<mutex> lock(m);
            while(turn < 2){
                cv.wait(lock);
            }

            releaseOxygen();
            turn = 0;
            cv.notify_all();
       
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        
    }
};
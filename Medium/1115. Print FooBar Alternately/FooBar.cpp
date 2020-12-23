class FooBar {
private:
    int n;
    mutex mufoo;
    mutex mubar;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            mufoo.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            mubar.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mubar.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            mufoo.unlock();
        }
    }
};
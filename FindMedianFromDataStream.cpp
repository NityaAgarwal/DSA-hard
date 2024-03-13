//https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
private:    
    priority_queue<int>maxi; //for left half of the sorted stream
    priority_queue<int, vector<int>, greater<int>>mini; //for right half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //step 1 - pushing the element into respective heap
        if (maxi.empty() || num <= maxi.top()) {
            maxi.push(num);
        }
        else mini.push(num);
        //step 2 - adjusting the size of the heaps
        //such that the heaps are of same size or 1 size diff at max
        if (maxi.size() > mini.size()+1) {
            mini.push(maxi.top());
            maxi.pop();
            return;
        }
        else if (mini.size() > maxi.size()) {
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if (maxi.size() == mini.size()) {
            //means stream has even number of values
            //then medium is avg of the top of maxi and mini
            return static_cast<double>((maxi.top()+mini.top())/2.0);
        }
        return static_cast<double>(maxi.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

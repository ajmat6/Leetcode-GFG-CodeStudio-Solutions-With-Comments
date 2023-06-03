// TC = O(nlogn) where are total no of elements in the stram
// SC = O(n) occupied by min heap and max heap

class MedianFinder {
public:
    priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	double median = -1;

    // function for comparing the size of the maxHeap and minHeap:
    int signum(int a, int b)
    {
    	if(a == b) return 0;
    	else if(a > b) return 1;
    	else return -1;
    }

    MedianFinder() {
        // no work of it
    }
    
    // function for inserting the new stream element into the data and then finding the new median
    void addNum(int num) {
        switch(signum(maxHeap.size(), minHeap.size()))
	    {
            // if both minHeap and maxHeap have equal size
            case 0:
                if(num > median)
                {
                    minHeap.push(num);
                    median = minHeap.top();
                }

                else
                {
                    maxHeap.push(num);
                    median = maxHeap.top();
                }
                break;

            // if maxHeap have greater size
            case 1:
                if(num > median)
                {
                    minHeap.push(num);
                    median = (minHeap.top() + maxHeap.top()) / 2.0;
                }

                else
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();

                    maxHeap.push(num);
                    median = (minHeap.top() + maxHeap.top()) / 2.0;
                }
                break;

            // if minHeap have greater size
            case -1:
                if(num > median)
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();

                    minHeap.push(num);
                    median = (minHeap.top() + maxHeap.top()) / 2.0;
                }

                else
                {
                    maxHeap.push(num);
                    median = (minHeap.top() + maxHeap.top()) / 2.0;
                }
                break;
	    }
    }
    
    double findMedian() {
        return median;
    }
};
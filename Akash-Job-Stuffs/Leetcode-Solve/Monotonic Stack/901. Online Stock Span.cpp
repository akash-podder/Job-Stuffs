class StockSpanner {
public:
    // We use a "Monotonic Decreasing" stack to keep track of stock prices and their respective spans. Each entry in the stack is an int[] array where:
    // 1st Element ---> represents the stock price
    // 2nd Element ---> represent the number of consecutive days the price has been equal to or greater than the previous days.
    
    // When a new price is encountered: We pop elements from the stack as long as they are smaller than or equal to the current price. The span of the current price is the sum of the popped elements' spans plus one. The current price and its span are then pushed onto the stack.

    // we are doing this because --> "maximum number of consecutive days is SPAN"... Read the Question again, you would understand

    stack<pair<int,int>> myStack;

    StockSpanner() {
        
    }
    
    int next(int current_price) {
        int days=0;
        while(!myStack.empty() && myStack.top().first<=current_price){
            days+=myStack.top().second;
            myStack.pop();
        }

        days=days+1; // because SPAN includes CURRENT DAY... so we have to Add "1" to count TODAY/CURRENT Day

        myStack.push(make_pair(current_price, days));

        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
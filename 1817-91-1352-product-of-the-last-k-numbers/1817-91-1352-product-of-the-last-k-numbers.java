class ProductOfNumbers {
    ArrayList<Integer> list;

    public ProductOfNumbers() {
        list = new ArrayList<>();
    }
    
    public void add(int num) {
        list.add(num);
    }
    
    public int getProduct(int k) {
        int pd = 1;

        int i = list.size()-1;
        int count = 0;

        while(i >= 0 && count != k){
            count++;
            pd = pd*list.get(i);
            i--;
        }
        return pd;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
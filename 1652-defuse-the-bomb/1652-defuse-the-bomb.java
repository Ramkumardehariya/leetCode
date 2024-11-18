class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        if (k == 0) return new int[n];

        int[] pre = new int[n];
        int[] res = new int[n];
        boolean isReversed = false;

        if (k < 0) {
            reverse(code);
            k = -k;
            isReversed = true;
        }

        // Compute prefix sum
        pre[0] = code[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + code[i];
        }

        // Calculate result using prefix sum
        for (int i = 0; i < n; i++) {
            if (i + k < n) {
                res[i] = pre[i + k] - pre[i];
            } else {
                res[i] = (pre[n - 1] - pre[i]) + pre[(i + k) % n];
            }
        }

        if (isReversed) {
            reverse(res);
        }
        
        return res;
    }

    private void reverse(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left++] = arr[right];
            arr[right--] = temp;
        }
    }
}
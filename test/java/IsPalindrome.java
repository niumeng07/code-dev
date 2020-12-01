class IsPalindrome {
    public static boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            while (!Character.isLetterOrDigit(s.charAt(left))) {
                left++;
                if (left > right)
                    break;
            }
            while (!Character.isLetterOrDigit(s.charAt(right))) {
                right--;
                if (left > right)
                    break;
            }
            if (left >= s.length() || right < 0) return true;
            if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    public static void main(String[] args) {
        if (isPalindrome("A man, a plan, a canal: Panama"))
            System.out.println("A1");
        if (isPalindrome("-----++++++"))
            System.out.println("B1");
        if (isPalindrome("-----a++++++ab"))
            System.out.println("C1");
        if (isPalindrome(""))
            System.out.println("D1");
        if (isPalindrome("a"))
            System.out.println("E1");
    }
}

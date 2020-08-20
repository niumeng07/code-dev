import java.util.Arrays;

class EnumTest {
    public enum YesOrNo {
        NO(0, "No"), YES(1, "Yes"), UNKNOWN(2, "Unknown");

        @EnumValue
        private Integer code;
        private String desc;

        YesOrNo(Integer code, String desc) {
            this.desc = desc;
            this.code = code;
        }

        public static YesOrNo codeOf(Integer require) {
            return Arrays.stream(values()).filter(yesOrNo -> yesOrNo.equals(require));
        }

        public Integer getCode() {
            return code;
        }

        public String getDesc() {
            return desc;
        }
    }

    public static void main(String[] args) {
        System.out.println(YesOrNo.YES.getCode());
    }
}

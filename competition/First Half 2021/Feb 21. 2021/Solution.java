import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

public class Solution {
    private static final String AES = "AES";
    private static final String UTF_8 = "utf-8";

    public static String generatePassport(String key) throws Exception {
        String src = "A324F6F548CF8BF390A3B783B560D7AFC1F72A4F55312238F2888457C0F5143F0BA67FF66B7E615313F9B6D42904E0460FD9FE99C6A9A64A1DFA93FE41C68F31";
        return decrypt(src, key + "口令leetcode1024");
    }

    public static String decrypt(String src, String key) throws Exception {
        byte[] raw = key.getBytes(UTF_8);
        byte[] trimmed = new byte[16];
        System.arraycopy(raw, 0, trimmed, 0, trimmed.length);
        SecretKeySpec skeySpec = new SecretKeySpec(trimmed, AES);
        Cipher cipher = Cipher.getInstance(AES);
        cipher.init(Cipher.DECRYPT_MODE, skeySpec);
        return new String(cipher.doFinal(hex2byte(src)), UTF_8);
    }

    public static byte[] hex2byte(String hex) {
        if (hex == null) {
            return null;
        }
        int L = hex.length();
        if (L % 2 == 1) {
            return null;
        }
        byte[] b = new byte[L / 2];
        for (int i = 0; i != L / 2; i++) {
            b[i] = (byte) Integer.parseInt(
                    hex.substring(i * 2, i * 2 + 2), 16);
        }
        return b;
    }

    public static void main(String[] args) throws Exception {
        String str = "刷题";
        System.out.println(generatePassport(str));
    }
}
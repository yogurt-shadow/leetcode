import java.util.*;

class Solution721 {
     public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, Integer> email2index = new HashMap<>();
        Map<String, String> email2name = new HashMap<>();
        int emailindex = 0;
        for(List<String> account: accounts){
            for(int i = 1; i < account.size(); i++){
                if(!email2index.containsKey(account.get(i))){
                    email2index.put(account.get(i), emailindex);
                    emailindex += 1;
                    email2name.put(account.get(i), account.get(0));
                }
            }
        }

        UnionFind uf = new UnionFind(emailindex);
        for(List<String> account: accounts){
            String email1 = account.get(1);
            for(int i = 2; i < account.size(); i++){
                uf.connect(email2index.get(email1), email2index.get(account.get(i)));
            }
        }

        Map<Integer, List<String>> index2email = new HashMap<>();
        for(String email: email2index.keySet()){
            int parent = uf.findparent(email2index.get(email));
            if(!index2email.containsKey(parent)){
                index2email.put(parent, new ArrayList<>());
            }
            if(!index2email.get(parent).contains(email)){
                index2email.get(parent).add(email);
            }
        }

        List<List<String>> result = new ArrayList<>();
      for(List<String> emails: index2email.values()){
        Collections.sort(emails);
        String name = email2name.get(emails.get(0));
        List<String> cur = new ArrayList<>();
        cur.add(name);
       cur.addAll(emails);
        result.add(cur);
      }
      return result;

    }

    public static void main(String[] args){
    	Solution721 s = new Solution721();
    	String str1 = "johnsmith@mail.com";
    	String str2 = "john_newyork@mail.com";
        String str3 = "john00@mail.com";
        String str4 = "johnnybravo@mail.com";
    	List<List<String>> accounts = new ArrayList<>();
        List<String> list1 = new ArrayList<>();
        list1.add("john");
        list1.add(str1);
        list1.add(str3);
        accounts.add(list1);

        List<String> list2 = new ArrayList<>();
        list2.add("john");
        list2.add(str4);
        accounts.add(list2);

        List<String> list3 = new ArrayList<>();
        list3.add("john");
        list3.add(str1);
        list3.add(str2);
        accounts.add(list3);

        List<String> list4 = new ArrayList<>();
        list4.add("Mary");
        list4.add("mary@mail.com");
        accounts.add(list4);

        List<List<String>> result = s.accountsMerge(accounts);
        for(List<String> ele: result){
            System.out.println(ele);
        }
    }
}
class RandomizedCollection {

    private Map<Integer, Set<Integer>> map;
    private List<Integer> list;
    private SecureRandom random;

    public RandomizedCollection() {
        this.map = new HashMap<>();
        this.list = new ArrayList<>();
        this.random = new SecureRandom();
    }

    public boolean insert(int val) {
        boolean containsKey = map.containsKey(val);
        if (!containsKey) {
            map.put(val, new LinkedHashSet<>());
        }
        map.get(val).add(list.size());
        list.add(val);
        return !containsKey;
    }

    public boolean remove(int val) {
        if (!map.containsKey(val)) {
            return false;
        }
        int lastVal = list.get(list.size() - 1);
        int valIndex = map.get(val).iterator().next();

        list.set(valIndex, lastVal);
        map.get(val).remove(valIndex);

        if (valIndex != list.size() - 1) {
            map.get(lastVal).remove(list.size() - 1);
            map.get(lastVal).add(valIndex);
        }
        list.remove(list.size() - 1);

        if (map.get(val).isEmpty()) {
            map.remove(val);
        }

        return true;
    }

    public int getRandom() {
        return list.get(random.nextInt(list.size()));
    }
}
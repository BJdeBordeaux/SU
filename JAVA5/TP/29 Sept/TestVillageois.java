public class TestVillageois{
	public static void main(String[] args){
		Villageois  v1 = new Villageois("Arnaud");
		Villageois  v2 = new Villageois("Bertrand");
		Villageois  v3 = new Villageois("Camille");
		Villageois  v4 = new Villageois("Damien");

		System.out.println(v1.toString());
		System.out.println(v2.toString());
		System.out.println(v3.toString());
		System.out.println(v4.toString());

		double tot = v1.poidsSouleve()+v2.poidsSouleve()+v3.poidsSouleve()+v4.poidsSouleve();
		if(tot >= 100){
			System.out.println("Reussi!");
		}else{
			System.out.println("Perdu!");
		}
	}
}
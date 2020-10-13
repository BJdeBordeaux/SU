public class TestPoint{
	public static void main(String[] args){
		Point pa = new Point();
		Point pb = new Point(3,5);
		System.out.println(pa.toString());
		System.out.println(pb.getPosx() + "," + pb.getPosy());
		System.out.println(pb.distance(pa));
		pa.setPosx(0);
		pa.setPosy(0);
		pb.deplaceToi(3,4);
		System.out.println(pa.toString());
		System.out.println(pb.getPosx() + "," + pb.getPosy());
		System.out.println(pa.distance(pb));
	}
}
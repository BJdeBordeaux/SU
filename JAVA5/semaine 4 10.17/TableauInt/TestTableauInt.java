public class TestTableauInt{
	public static void main(String[] args){
		TableauInt ta = new TableauInt();
		TableauInt tb = new TableauInt(15);
		TableauInt tc = new TableauInt(15);

		System.out.println(ta.toString());
		System.out.println(tb.toString());
		System.out.println(tc.toString());
		System.out.println(ta.rangMax());
		System.out.println(tb.rangMax());
		System.out.println(tb.egal(tc));

	}
}
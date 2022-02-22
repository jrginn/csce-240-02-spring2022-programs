//Written by Jackson Ginn
//import java.util.ArrayList;

//This class takes a string formatted by tabs and 
public class InfoSet {
	//instance variables
	private String title;
	private String[] facts;
	
	//constructor
	public InfoSet(String str) {
		//splits string based on tabs
		String[] lines = str.split("\t");
		if(lines.length == 1) { //no other information besides title
			title = lines[0];
			facts = null;
		}
		else {
			title = lines[0];
			facts = new String[lines.length-1];
			//loops through lines and adds them to facts array
			for(int i = 1; i  < lines.length; i++) {
				facts[i-1] = lines[i];
			}
		}
	}
	
	//accessor methods
	public String getTitle() {
		return title;
	}
	
	public String[] getFacts() {
		return facts;
	}
	
	//string representation
	public String toString() {
		if(facts == null) {
			return title;
		}
		else {
			String ret = title;
			for(int i = 0; i < facts.length; i++) {
				ret += "\n" + facts[i];
			}
			return ret;
		}
	}
}

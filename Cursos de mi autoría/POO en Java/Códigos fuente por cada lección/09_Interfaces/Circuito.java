
public class Circuito {
	public String modelo;
	public double voltaje_total;
	public double amperaje_total;
	public boolean ON;
	
	public Circuito(String modelo,double voltaje_total, double amperaje_total, boolean ON) {
		this.modelo = modelo;
		this.voltaje_total = voltaje_total;
		this.amperaje_total = amperaje_total;
		this.ON = ON;
	}
	
	public boolean ON() {
		System.out.println(modelo+" - ON");
		ON = true;
		return true;
	}
	
	public boolean OFF() {
		System.out.println(modelo+" - OFF");
		ON = false;
		return false;
	}
	
	// Getters y setters ------------------
	
	// SETTERS ----------------------------
	public void setModelo(String modelo) {
		this.modelo = modelo;
		return;
	}
	
	public void setVoltaje_total(double voltaje_total) {
		this.voltaje_total = voltaje_total;
		return;
	}

	public void setAmperajetotal(double amperaje_total) {
		this.amperaje_total = amperaje_total;
		return;
	}

	public void setOn(boolean ON) {
		this.ON = ON;
		return;
	}
	
	// GETTERS ----------------------------
	public String getModelo() {
		return modelo;
	}
	
	public double getVoltajetotal() {
		return voltaje_total;
	}

	public double getAmperajetotal() {
		return amperaje_total;
	}

	public boolean getOn() {
		return ON;
	}
	
}


public interface MOTOR_DC{
	public double voltaje = 2.5;
	public double amperaje = 0.5;
	
	public boolean MOTOR_ON(double power, short pin_sender);// !!!!
	public boolean MOTOR_OFF();
	public boolean INTERFACE_ARD_WITH_MOTOR_DC();// !!!!

}

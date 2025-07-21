
public interface Arduino {
	public short pin1 = 1;
	public short pin2 = 2;
	public short pin3 = 3;
	public short pin4 = 4;
	public double voltaje = 5.0;
	public double amperaje = 1.0;
	
	public boolean ARD_ON();
	public boolean ARD_OFF();
	public boolean ARD_RUN();
	public boolean INTERFACE_ARD_WITH_MOTOR_DC();// !!!!
	
}

// vehicle 
public abstract class Vehicle {  
    private String licensePlate; // Stores the vehicle's license plate number
    private String vehicleType; // Stores the type of vehicle (e.g., car, bike, truck)
    private ParkingFeeStrategy feeStrategy; // Strategy for calculating parking fees
    // Constructor to initialize a vehicle with its license plate, type, and fee strategy
    public Vehicle(String licensePlate, String vehicleType, ParkingFeeStrategy feeStrategy) {  
        this.licensePlate = licensePlate;  
        this.vehicleType = vehicleType;  
        this.feeStrategy = feeStrategy;  
    }  
    // Getter method to retrieve the vehicle type
    public String getVehicleType() {  
        return vehicleType;  
    }  
    // Getter method to retrieve the vehicle's license plate number
    public String getLicensePlate() {  
        return licensePlate;  
    }  
    // Method to calculate parking fee based on duration and duration type
    public double calculateFee(int duration, DurationType durationType) {  
        return feeStrategy.calculateFee(vehicleType, duration, durationType);
    }  
}

public class CarVehicle extends Vehicle { 
    public CarVehicle(String licensePlate, ParkingFeeStrategy feeStrategy) { 
        super(licensePlate, "Car", feeStrategy); 
    } 
}
public class BikeVehicle extends Vehicle { 
    public BikeVehicle(String licensePlate, ParkingFeeStrategy feeStrategy) { 
        super(licensePlate, "Bike", feeStrategy); 
    } 
}

public class VehicleFactory {
    public static Vehicle createVehicle(
        String vehicleType, String licensePlate, ParkingFeeStrategy feeStrategy) {
      if (vehicleType.equalsIgnoreCase("Car")) {
        return new CarVehicle(licensePlate, feeStrategy);
      } else if (vehicleType.equalsIgnoreCase("Bike")) {
        return new BikeVehicle(licensePlate, feeStrategy);
      }
      return new OtherVehicle(
          licensePlate, feeStrategy); // For unsupported vehicle types
    }
  }


// parking slot 
// public class ParkingSlot {
//     private VehicleType slotType;
//     private boolean isOccupied; 
// }
public abstract class ParkingSpot {
    private int spotNumber;
    private boolean isOccupied;
    private Vehicle vehicle;
    private String spotType;
    // Constructor to initialize parking spot with spot number and type
    public ParkingSpot(int spotNumber, String spotType) {
      this.spotNumber = spotNumber;
      this.isOccupied = false;
      this.spotType = spotType;
    }
    // Method to check if the spot is occupied
    public boolean isOccupied() {
      return isOccupied;
    }
    // Abstract method to check if a vehicle can park in this spot
    public abstract boolean canParkVehicle(Vehicle vehicle);
    // Method to park a vehicle in the spot
    public void parkVehicle(Vehicle vehicle) {
      // Check if the spot is already occupied
      if (isOccupied) {
        throw new IllegalStateException("Spot is already occupied.");
      }
      // Check if the vehicle can be parked in this spot
      if (!canParkVehicle(vehicle)) {
        throw new IllegalArgumentException(
            "This spot is not suitable for" + vehicle.getVehicleType());
      }
      this.vehicle = vehicle;
      this.isOccupied = true;
    }
    // Method to vacate the parking spot
    public void vacate() {
      // Check if the spot is already vacant
      if (!isOccupied) {
        throw new IllegalStateException("Spot is already vacant.");
      }
      this.vehicle = null;
      this.isOccupied = false;
    }
    // Getter for spot number
    public int getSpotNumber() {
      return spotNumber;
    }
    // Getter for the vehicle parked in the spot
    public Vehicle getVehicle() {
      return vehicle;
    }
    // Getter for spot type
    public String getSpotType() {
      return spotType;
    }
  }

public class CarParkingSpot extends ParkingSpot {
    public CarParkingSpot(int spotNumber) {
        super(spotNumber, "Car");
    }
    @Override
    public boolean canParkVehicle(Vehicle vehicle) {
        return "Car".equalsIgnoreCase(vehicle.getVehicleType());
    }
}


//payment
public interface PaymentStrategy { 
    boolean processPayment(double amount);
}

public class CashPayment implements PaymentStrategy {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing cash payment of $" + amount);
        // Logic for cash payment processing
    }
}
public class Payment {
    private double amount;
    private PaymentStrategy paymentStrategy; // Payment strategy interface
    // Constructor to initialize the payment amount and payment strategy
    public Payment(double amount, PaymentStrategy paymentStrategy) {
        this.amount = amount;
        this.paymentStrategy = paymentStrategy;
    }
    // Process the payment using the assigned strategy
    public void processPayment() {
        if (amount > 0) {
            paymentStrategy.processPayment(amount);  // Delegating to strategy
        } else {
            System.out.println("Invalid payment amount.");
        }
    }
}

// parking Fee
// Enum to specify duration type
public enum DurationType {
    HOURS, 
    DAYS
}

public interface ParkingFeeStrategy {
    /**
     - Calculate parking fee based on vehicle type and duration
     - 
     - @param vehicleType Type of vehicle being parked
     - @param duration Duration of parking (in hours or days)
     - @param durationType Type of duration (HOURS or DAYS)
     - @return Calculated parking fee
     */
    double calculateFee(String vehicleType, int duration, DurationType durationType);
}
public class BasicHourlyRateStrategy implements ParkingFeeStrategy {
    @Override
    public double calculateFee(String vehicleType, int duration, DurationType durationType) {
        // Different rates for different vehicle types
        switch (vehicleType.toLowerCase()) {
            case "car":
                return durationType == DurationType.HOURS 
                    ? duration * 10.0   // $10 per hour for cars
                    : duration * 10.0 * 24;  // Daily rate

            // ........
            default:
                return durationType == DurationType.HOURS 
                    ? duration * 15.0   // $15 per hour for other vehicles
                    : duration * 15.0 * 24;  // Daily rate
        }
    }
}



// parking lot
// public class ParkingLot {
//     private List<ParkingSlot> slots; 
// }
public class ParkingLot {
    private List<ParkingSpot> parkingSpots;
    // Constructor to initialize the parking lot with parking spots
    public ParkingLot(List<ParkingSpot> parkingSpots) {
      this.parkingSpots = parkingSpots;
    }
    // Method to find an available spot based on vehicle type
    public ParkingSpot findAvailableSpot(String vehicleType) {
      for (ParkingSpot spot : parkingSpots) {
        if (!spot.isOccupied() && spot.getSpotType().equals(vehicleType)) {
          return spot; // Found an available spot for the vehicle type
        }
      }
      return null; // No available spot found for the given vehicle type
    }
    // Method to park a vehicle
    public ParkingSpot parkVehicle(Vehicle vehicle) {
      ParkingSpot spot = findAvailableSpot(vehicle.getVehicleType());
      if (spot != null) {
        spot.parkVehicle(vehicle); // Mark the spot as occupied
        System.out.println(
            "Vehicle parked successfully in spot: " + spot.getSpotNumber());
        return spot;
      }
      System.out.println(
          "No parking spots available for " + vehicle.getVehicleType() + "!");
      return null;
    }
    // Method to vacate a parking spot
    public void vacateSpot(ParkingSpot spot, Vehicle vehicle) {
      if (spot != null && spot.isOccupied()
          && spot.getVehicle().equals(vehicle)) {
        spot.vacate(); // Free the spot
        System.out.println(vehicle.getVehicleType()
            + " vacated the spot: " + spot.getSpotNumber());
      } else {
        System.out.println("Invalid operation! Either the spot is already vacant "
                           + "or the vehicle does not match.");
      }
    }
    // Method to find a spot by its number
    public ParkingSpot getSpotByNumber(int spotNumber) {
      for (ParkingSpot spot : parkingSpots) {
        if (spot.getSpotNumber() == spotNumber) {
          return spot;
        }
      }
      return null; // Spot not found
    }
    // Getter for parking spots
    public List<ParkingSpot> getParkingSpots() {
      return parkingSpots;
    }
}




// Now main function 
public class ParkingLotMain {
    public static void main(String[] args) {
      // Initialize parking spots
      List<ParkingSpot> parkingSpots = new ArrayList<>();
      parkingSpots.add(new CarParkingSpot(1));
      parkingSpots.add(new CarParkingSpot(2));
      parkingSpots.add(new BikeParkingSpot(3));
      parkingSpots.add(new BikeParkingSpot(4));
      // Initialize parking lot
      ParkingLot parkingLot = new ParkingLot(parkingSpots);
      // Create fee strategies
      ParkingFeeStrategy basicHourlyRateStrategy = new BasicHourlyRateStrategy();
      ParkingFeeStrategy premiumRateStrategy = new PremiumRateStrategy();
      // Create vehicles using Factory Pattern with fee strategies
      Vehicle car1 =
          VehicleFactory.createVehicle("Car", "CAR123", basicHourlyRateStrategy);
      Vehicle bike1 =
          VehicleFactory.createVehicle("Bike", "BIKE456", premiumRateStrategy);
      // Park vehicles
      ParkingSpot carSpot = parkingLot.parkVehicle(car1);
      ParkingSpot bikeSpot = parkingLot.parkVehicle(bike1);
      Scanner scanner = new Scanner(System.in);
      System.out.println("Select payment method for your vehicle:");
      System.out.println("1. Credit Card");
      System.out.println("2. Cash");
      int paymentMethod = scanner.nextInt();
      // Process payments using Strategy Patterns
      if (carSpot != null) {
        // Calculate fee using the specific strategy for the vehicle
        double carFee = car1.calculateFee(2, DurationType.HOURS);
        PaymentStrategy carPaymentStrategy =
            getPaymentStrategy(paymentMethod, carFee);
        carPaymentStrategy.processPayment(carFee);
        parkingLot.vacateSpot(carSpot, car1);
      }
      if (bikeSpot != null) {
        // Calculate fee using the specific strategy for the vehicle
        double bikeFee = bike1.calculateFee(3, DurationType.HOURS);
        PaymentStrategy bikePaymentStrategy =
            getPaymentStrategy(paymentMethod, bikeFee);
        bikePaymentStrategy.processPayment(bikeFee);
        parkingLot.vacateSpot(bikeSpot, bike1);
      }
      scanner.close();
    }
    private static PaymentStrategy getPaymentStrategy(
        int paymentMethod, double fee) {
      switch (paymentMethod) {
        case 1:
          return new CreditCardPayment(fee);
        case 2:
          return new CashPayment(fee);
        default:
          System.out.println("Invalid choice! Default to Credit card payment.");
          return new CreditCardPayment(fee);
      }
    }
}


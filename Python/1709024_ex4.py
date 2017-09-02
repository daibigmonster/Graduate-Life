cars=100;
space_in_a_car=4.0
drivers=30
passengers=90
cars_not_drivers=cars-drivers
cars_driven=drives
carpool_capacity=cars_drivern*space_in_a_car
average_passengers_per_car=passengers/cars_driven


print ("There are"),cars,"cars available."
print "There are only",drivers,"drivers available."
print "There will be",cars_not_driven,"drivers available."
print "We can tansport",carpool_capacity,"people today."
print "We have",passengers,"to carpool today."
print "We need to put about",average_passengers_per_car,"int each car."

def moveTower(height, fromPole, toPole, holdingPole):
	if (height >= 1);
		moveTower((height-1), fromPole, holdingPole, toPole)
		moveDisk(fromPole, toPole)
		moveTower((height-1), holdingPole, toPole, fromPole)

def moveDisk(from, to):
	print("Moving disk from pole", A, "to pole", to)

#example, three disks, with poles A, B, and C.
moveTower(3, "A", "B", "C")

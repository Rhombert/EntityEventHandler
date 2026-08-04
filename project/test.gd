extends Node

func _ready() -> void:
	var hp = Hp.create(400)
	print(hp.get_health())
	hp.damage(22)
	print(hp.get_health())

extends Node

func _ready() -> void:
	var event_handler := EntityEventHandlerGd.create(50, 1)

	var damage_instance: DamageGd = DamageGd.create(2)
	var modifier: ModifierGd = ModifierGd.new()
	modifier.set_effect(damage_instance)
	modifier.set_tick_num(10)

	var interaction: InteractionGd = InteractionGd.new()
	interaction.add(modifier)

	event_handler.receive_interaction(interaction);
	event_handler.print_state()

	event_handler._process(0.2)
	event_handler.print_state()

	event_handler._process(0.2)
	event_handler.print_state()

extends Node

func _ready() -> void:
	var event_handler: EntityEventHandlerGd = EntityEventHandlerGd.new()

	var damage_instance: DamageGd = DamageGd.new()
	var modifier: ModifierGd = ModifierGd.new()
	modifier.set_effect(damage_instance)

	var interaction: InteractionGd = InteractionGd.new()
	interaction.add(modifier)

	event_handler.receive_interaction(interaction);
	event_handler.print_state()

	event_handler._process(0)
	event_handler.print_state()

	event_handler._process(0)
	event_handler.print_state()

	# Future ticks not functioning, next bug to fix.
	event_handler._process(1)
	event_handler.print_state()

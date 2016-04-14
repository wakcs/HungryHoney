#include "stdafx.h"
#include "Pickup.h"


Pickup::Pickup()
{
	iPickupRange = 0;
}

Pickup::Pickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position, int pickupRange)
{
	sprtItem.setTexture(*itemTexture);
	sprtItem.setOrigin(sprtItem.getLocalBounds().width / 2, sprtItem.getLocalBounds().height / 2);
	sprtInteract.setTexture(*InteractTexture);
	sprtInteract.setOrigin(sprtInteract.getLocalBounds().width / 2, sprtInteract.getLocalBounds().height / 2);
	SetPosition(position);
	iPickupRange = pickupRange;
}


Pickup::~Pickup()
{
}

void Pickup::Update(PlayerCharacter * player)
{
	float distance = Vector2Extender::NormalizeFloat(sprtItem.getPosition(), player->sprtCharacter.getPosition());
	if (distance < iPickupRange)
	{
		bInRange = true;
	}
	else 
	{
		bInRange = false;
	}
}

void Pickup::Draw(RenderWindow & window)
{
	window.draw(sprtItem);
	if (bInRange) 
	{
		window.draw(sprtInteract);
	}
}

void Pickup::SetPosition(Vector2f position)
{
	sprtItem.setPosition(position);
	position.y -= sprtInteract.getLocalBounds().height;
	position.x += (sprtItem.getLocalBounds().width / 2) - (sprtInteract.getLocalBounds().width / 2);
	sprtInteract.setPosition(position);
}

#include "stdafx.h"
#include "Pickup.h"


Pickup::Pickup()
{
	iPickupRange = 0;
}

Pickup::Pickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position,SoundBuffer * bufPickup, int pickupRange)
{
	sprtItem.setTexture(*itemTexture);
	sprtItem.setOrigin(sprtItem.getLocalBounds().width / 2, sprtItem.getLocalBounds().height / 2);
	sprtInteract.setTexture(*InteractTexture);
	sprtInteract.setOrigin(sprtInteract.getLocalBounds().width / 2, sprtInteract.getLocalBounds().height / 2);
	SetPosition(position);
	iPickupRange = pickupRange;
	sndPickup.setBuffer(*bufPickup);
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
	if (bInRange && Keyboard::isKeyPressed(player->GetInteractKey())) {
		sndPickup.play();
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

// Fill out your copyright notice in the Description page of Project Settings.

#include "My_CPP_GameState.h"

AMy_CPP_GameState::AMy_CPP_GameState()
{
	CurrentScore = 0;
}

uint32 AMy_CPP_GameState::GetScore()
{
	return CurrentScore;
}

void AMy_CPP_GameState::SetScore(uint32 NewScore)
{
	CurrentScore = NewScore;
}
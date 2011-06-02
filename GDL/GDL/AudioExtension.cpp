#include "GDL/AudioExtension.h"
#include "GDL/cMusic.h"
#include "GDL/aMusic.h"
#include "GDL/ResourcesMergingHelper.h"
#include "GDL/Instruction.h"
#include "GDL/SoundManager.h"
#include "GDL/eFreeFunctions.h"
#include <iostream>

AudioExtension::AudioExtension()
{
    DECLARE_THE_EXTENSION("BuiltinAudio",
                          _("Audio"),
                          _("Extension audio integr�e en standard"),
                          "Compil Games",
                          "Freeware")

    DECLARE_ACTION("PlaySoundCanal",
                   _("Jouer un son sur un canal"),
                   _("Joue un son ( court fichier audio ) sur un canal pr�cis,\npour pouvoir ensuite interagir avec."),
                   _("Jouer le son _PARAM0_ sur le canal _PARAM1_"),
                   _("Sons"),
                   "res/actions/son24.png",
                   "res/actions/son.png",
                   &ActPlaySoundCanal);

        DECLARE_PARAMETER("soundfile", _("Fichier audio"), false, "")
        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER_OPTIONAL("yesorno", _("Boucler le son ?"), false, "")
        DECLARE_PARAMETER_OPTIONAL("expression", _("Volume ( De 0 � 100, 100 par d�faut )"), false, "")
        DECLARE_PARAMETER_OPTIONAL("expression", _("Pitch ( Vitesse ) ( 1 par d�faut )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("StopSoundCanal",
                   _("Arr�ter le son sur un canal"),
                   _("Arr�ter le son jou� sur le canal indiqu�."),
                   _("Arr�ter le son du canal _PARAM0_"),
                   _("Sons"),
                   "res/actions/son24.png",
                   "res/actions/son.png",
                   &ActStopSoundCanal);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("PauseSoundCanal",
                   _("Mettre en pause le son d'un canal"),
                   _("Mettre en pause le son jou� sur le canal indiqu�."),
                   _("Mettre en pause le son du canal _PARAM0_"),
                   _("Sons"),
                   "res/actions/son24.png",
                   "res/actions/son.png",
                   &ActPauseSoundCanal);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("RePlaySoundCanal",
                   _("Jouer le son d'un canal"),
                   _("(Re)jouer le son du canal."),
                   _("Jouer le son du canal _PARAM0_"),
                   _("Sons"),
                   "res/actions/son24.png",
                   "res/actions/son.png",
                   &ActRePlaySoundCanal);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("PlayMusicCanal",
                   _("Jouer une musique sur un canal"),
                   _("Joue une musique sur un canal pr�cis,\npour pouvoir ensuite interagir avec."),
                   _("Jouer la musique _PARAM0_ sur le canal _PARAM1_"),
                   _("Musiques"),
                   "res/actions/music24.png",
                   "res/actions/music.png",
                   &ActPlayMusicCanal);

        DECLARE_PARAMETER("musicfile", _("Fichier audio"), false, "")
        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER_OPTIONAL("yesorno", _("Boucler le son ?"), false, "")
        DECLARE_PARAMETER_OPTIONAL("expression", _("Volume ( De 0 � 100, 100 par d�faut )"), false, "")
        DECLARE_PARAMETER_OPTIONAL("expression", _("Pitch ( Vitesse ) ( 1 par d�faut )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("StopMusicCanal",
                   _("Arr�ter la musique sur un canal"),
                   _("Arr�ter la musique jou�e sur le canal indiqu�."),
                   _("Arr�ter la musique du canal _PARAM0_"),
                   _("Musiques"),
                   "res/actions/music24.png",
                   "res/actions/music.png",
                   &ActStopMusicCanal);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("PauseMusicCanal",
                   _("Mettre en pause la musique d'un canal"),
                   _("Mettre en pause la musique jou�e sur le canal indiqu�."),
                   _("Mettre en pause la musique du canal _PARAM0_"),
                   _("Musiques"),
                   "res/actions/music24.png",
                   "res/actions/music.png",
                   &ActPauseMusicCanal);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("RePlayMusicCanal",
                   _("Jouer la musique d'un canal"),
                   _("(Re)jouer la musique du canal."),
                   _("Jouer la musique du canal _PARAM0_"),
                   _("Musiques"),
                   "res/actions/music24.png",
                   "res/actions/music.png",
                   &ActRePlayMusicCanal);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModVolumeSoundCanal",
                   _("Volume d'un son sur un canal"),
                   _("Cette action modifie le volume du son sur le canal sp�cifi�. Le volume est compris entre 0 et 100."),
                   _("Faire _PARAM2__PARAM1_ au volume du son sur le canal  _PARAM0_"),
                   _("Volume sonore"),
                   "res/actions/sonVolume24.png",
                   "res/actions/sonVolume.png",
                   &ActModVolumeSoundCanal);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Valeur"), false, "")
        DECLARE_PARAMETER("signe", _("Signe de la modification"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModVolumeMusicCanal",
                   _("Volume de la musique d'un canal"),
                   _("Cette action modifie le volume de la musique sur le canal sp�cifi�. Le volume est compris entre 0 et 100."),
                   _("Faire _PARAM2__PARAM1_ au volume de la musique du canal  _PARAM0_"),
                   _("Volume sonore"),
                   "res/actions/sonVolume24.png",
                   "res/actions/sonVolume.png",
                   &ActModVolumeMusicCanal);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Valeur"), false, "")
        DECLARE_PARAMETER("signe", _("Signe de la modification"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModGlobalVolume",
                   _("Volume global du jeu"),
                   _("Cette action modifie le volume sonore global du jeu. Le volume est compris entre 0 et 100."),
                   _("Faire _PARAM1__PARAM0_ au volume sonore global"),
                   _("Volume sonore"),
                   "res/actions/volume24.png",
                   "res/actions/volume.png",
                   &ActModGlobalVolume);

        DECLARE_PARAMETER("expression", _("Valeur"), false, "")
        DECLARE_PARAMETER("signe", _("Signe de la modification"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModPitchSoundChannel",
                   _("Pitch d'un son sur un canal"),
                   _("Cette action modifie le pitch ( vitesse ) du son d'un canal.\nUn pitch de 1 indique une vitesse normale."),
                   _("Faire _PARAM2__PARAM1_ au pitch du son sur le canal _PARAM0_"),
                   _("Sons"),
                   "res/actions/son24.png",
                   "res/actions/son.png",
                   &ActModPitchSoundChannel);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Valeur"), false, "")
        DECLARE_PARAMETER("signe", _("Signe de la modification"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModPitchMusicChannel",
                   _("Pitch de la musique d'un canal"),
                   _("Cette action modifie le pitch de la musique sur un canal.\nUn pitch de 1 indique une vitesse normale."),
                   _("Faire _PARAM2__PARAM1_ au pitch de la musique du canal _PARAM0_"),
                   _("Musiques"),
                   "res/actions/music24.png",
                   "res/actions/music.png",
                   &ActModPitchMusicChannel);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Valeur"), false, "")
        DECLARE_PARAMETER("signe", _("Signe de la modification"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModPlayingOffsetSoundChannel",
                   _("Position de lecture d'un son sur un canal"),
                   _("Cette action modifie la position de lecture du son d'un canal."),
                   _("Faire _PARAM2__PARAM1_s � la position de lecture du son sur le canal _PARAM0_"),
                   _("Sons"),
                   "res/actions/son24.png",
                   "res/actions/son.png",
                   &ActModPlayingOffsetSoundChannel);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Valeur"), false, "")
        DECLARE_PARAMETER("signe", _("Signe de la modification"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModPlayingOffsetMusicChannel",
                   _("Position de lecture de la musique d'un canal"),
                   _("Cette action modifie la position de lecture de la musique sur un canal."),
                   _("Faire _PARAM2__PARAM1_s � la position de lecture de la musique du canal _PARAM0_"),
                   _("Musiques"),
                   "res/actions/music24.png",
                   "res/actions/music.png",
                   &ActModPlayingOffsetMusicChannel);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Valeur"), false, "")
        DECLARE_PARAMETER("signe", _("Signe de la modification"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("PlaySound",
                   _("Jouer un son"),
                   _("Joue un son."),
                   _("Jouer le son _PARAM0_"),
                   _("Sons"),
                   "res/actions/son24.png",
                   "res/actions/son.png",
                   &ActPlaySound);

        DECLARE_PARAMETER("soundfile", _("Fichier audio"), false, "")
        DECLARE_PARAMETER_OPTIONAL("yesorno", _("Boucler le son ?"), false, "")
        DECLARE_PARAMETER_OPTIONAL("expression", _("Volume ( De 0 � 100, 100 par d�faut )"), false, "")
        DECLARE_PARAMETER_OPTIONAL("expression", _("Pitch ( Vitesse ) ( 1 par d�faut )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_ACTION("PlayMusic",
                   _("Jouer une musique"),
                   _("Joue une musique."),
                   _("Jouer la musique _PARAM0_"),
                   _("Musiques"),
                   "res/actions/music24.png",
                   "res/actions/music.png",
                   &ActPlayMusic);

        DECLARE_PARAMETER("musicfile", _("Fichier audio"), false, "")
        DECLARE_PARAMETER_OPTIONAL("yesorno", _("Boucler le son ?"), false, "")
        DECLARE_PARAMETER_OPTIONAL("expression", _("Volume ( De 0 � 100, 100 par d�faut )"), false, "")
        DECLARE_PARAMETER_OPTIONAL("expression", _("Pitch ( Vitesse ) ( 1 par d�faut )"), false, "")

    DECLARE_END_ACTION()

    DECLARE_CONDITION("MusicPlaying",
                   _("Une musique est entrain d'�tre jou�e"),
                   _("Teste si la musique sur le canal indiqu� est entrain d'�tre jou�e."),
                   _("La musique sur le canal _PARAM0_ est entrain d'�tre jou�e"),
                   _("Musiques"),
                   "res/conditions/musicplaying24.png",
                   "res/conditions/musicplaying.png",
                   &CondMusicPlaying);

        DECLARE_PARAMETER("expression", _("Canal"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicPaused",
                   _("Une musique est en pause"),
                   _("Teste si la musique sur le canal indiqu� est en pause."),
                   _("La musique sur le canal _PARAM0_ est en pause"),
                   _("Musiques"),
                   "res/conditions/musicpaused24.png",
                   "res/conditions/musicpaused.png",
                   &CondMusicPaused);

        DECLARE_PARAMETER("expression", _("Canal"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicStopped",
                   _("Une musique est arr�t�e"),
                   _("Teste si la musique sur le canal indiqu� est arr�t�e."),
                   _("La musique sur le canal _PARAM0_ est arr�t�e"),
                   _("Musiques"),
                   "res/conditions/musicstopped24.png",
                   "res/conditions/musicstopped.png",
                   &CondMusicStopped);

        DECLARE_PARAMETER("expression", _("Canal"), false, "")

    DECLARE_END_CONDITION()
    DECLARE_CONDITION("SoundPlaying",
                   _("Un son est entrain d'�tre jou�e"),
                   _("Teste si le son sur le canal indiqu� est entrain d'�tre jou�."),
                   _("Le son sur le canal _PARAM0_ est entrain d'�tre jou�"),
                   _("Sons"),
                   "res/conditions/sonplaying24.png",
                   "res/conditions/sonplaying.png",
                   &CondSoundPlaying);

        DECLARE_PARAMETER("expression", _("Canal"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundPaused",
                   _("Un son est en pause"),
                   _("Teste si le son sur le canal indiqu� est en pause."),
                   _("Le son sur le canal _PARAM0_ est en pause"),
                   _("Sons"),
                   "res/conditions/sonpaused24.png",
                   "res/conditions/sonpaused.png",
                   &CondSoundPaused);

        DECLARE_PARAMETER("expression", _("Canal"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundStopped",
                   _("Un son est arr�t�e"),
                   _("Teste si le son sur le canal indiqu� est arr�t�."),
                   _("Le son sur le canal _PARAM0_ est arr�t�"),
                   _("Sons"),
                   "res/conditions/sonstopped24.png",
                   "res/conditions/sonstopped.png",
                   &CondSoundStopped);

        DECLARE_PARAMETER("expression", _("Canal"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundCanalVolume",
                   _("Volume d'un son sur un canal"),
                   _("Teste le volume du son sur le canal indiqu�. Le volume est compris entre 0 et 100."),
                   _("Le volume du son sur le canal _PARAM0_ est _PARAM2_ � _PARAM1_"),
                   _("Volume sonore"),
                   "res/conditions/sonVolume24.png",
                   "res/conditions/sonVolume.png",
                   &CondSoundCanalVolume);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Volume � tester"), false, "")
        DECLARE_PARAMETER("signe", _("Signe du test"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicCanalVolume",
                   _("Volume de la musique sur un canal"),
                   _("Teste le volume de la musique sur le canal indiqu�. Le volume est compris entre 0 et 100."),
                   _("Le volume de la musique sur le canal _PARAM0_ est _PARAM2_ � _PARAM1_"),
                   _("Volume sonore"),
                   "res/conditions/musicVolume24.png",
                   "res/conditions/musicVolume.png",
                   &CondMusicCanalVolume);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Volume � tester"), false, "")
        DECLARE_PARAMETER("signe", _("Signe du test"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("GlobalVolume",
                   _("Volume sonore global"),
                   _("V�rifie que le volume sonore global correspond au test. Le volume est compris entre 0 et 100."),
                   _("Le volume sonore global est _PARAM1_ � _PARAM0_"),
                   _("Volume sonore"),
                   "res/conditions/volume24.png",
                   "res/conditions/volume.png",
                   &CondGlobalVolume);

        DECLARE_PARAMETER("expression", _("Volume � tester"), false, "")
        DECLARE_PARAMETER("signe", _("Signe du test"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundChannelPitch",
                   _("Pitch du son d'un canal"),
                   _("Teste le pitch ( vitesse ) du son sur le canal indiqu�. Un pitch de 1 indique une vitesse normale."),
                   _("Le pitch du son sur le canal _PARAM0_ est _PARAM2_ � _PARAM1_"),
                   _("Sons"),
                   "res/conditions/sonVolume24.png",
                   "res/conditions/sonVolume.png",
                   &CondSoundChannelPitch);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Pitch � tester"), false, "")
        DECLARE_PARAMETER("signe", _("Signe du test"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicChannelPitch",
                   _("Pitch de la musique d'un canal"),
                   _("Teste le pitch ( vitesse ) de la musique sur le canal indiqu�. Un pitch de 1 indique une vitesse normale."),
                   _("Le volume de la musique sur le canal _PARAM0_ est _PARAM2_ � _PARAM1_"),
                   _("Musiques"),
                   "res/conditions/musicVolume24.png",
                   "res/conditions/musicVolume.png",
                   &CondMusicChannelPitch);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Pitch � tester"), false, "")
        DECLARE_PARAMETER("signe", _("Signe du test"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundChannelPlayingOffset",
                   _("Position de lecture du son d'un canal"),
                   _("Teste la position de lecture du son sur le canal indiqu�."),
                   _("La position de lecture du son sur le canal _PARAM0_ est _PARAM2_ � _PARAM1_s"),
                   _("Sons"),
                   "res/conditions/sonVolume24.png",
                   "res/conditions/sonVolume.png",
                   &CondSoundChannelPlayingOffset);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Position � tester ( en secondes )"), false, "")
        DECLARE_PARAMETER("signe", _("Signe du test"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicChannelPlayingOffset",
                   _("Position de lecture de la musique d'un canal"),
                   _("Teste la position de lecture de la musique sur le canal indiqu�."),
                   _("La position de lecture la musique sur le canal _PARAM0_ est _PARAM2_ � _PARAM1_s"),
                   _("Musiques"),
                   "res/conditions/musicVolume24.png",
                   "res/conditions/musicVolume.png",
                   &CondMusicChannelPlayingOffset);

        DECLARE_PARAMETER("expression", _("Canal ( 0 � 15 )"), false, "")
        DECLARE_PARAMETER("expression", _("Position � tester ( en secondes )"), false, "")
        DECLARE_PARAMETER("signe", _("Signe du test"), false, "")

    DECLARE_END_CONDITION()

    DECLARE_EXPRESSION("SoundChannelPlayingOffset", _("Position de lecture d'un son"), _("Position de lecture d'un son"), _("Sons"), "res/actions/son.png", &ExpGetSoundChannelPlayingOffset)
        DECLARE_PARAMETER("expression", _("Canal"), false, "")
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("MusicChannelPlayingOffset", _("Position de lecture d'une musique"), _("Position de lecture d'une musique"), _("Musiques"), "res/actions/music.png", &ExpGetMusicChannelPlayingOffset)
        DECLARE_PARAMETER("expression", _("Canal"), false, "")
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("SoundChannelVolume", _("Volume d'un son"), _("Volume d'un son"), _("Sons"), "res/actions/son.png", &ExpGetSoundChannelVolume)
        DECLARE_PARAMETER("expression", _("Canal"), false, "")
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("MusicChannelVolume", _("Volume d'une musique"), _("Volume d'une musique"), _("Musiques"), "res/actions/music.png", &ExpGetMusicChannelVolume)
        DECLARE_PARAMETER("expression", _("Canal"), false, "")
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("SoundChannelPitch", _("Pitch d'un son"), _("Pitch d'un son"), _("Sons"), "res/actions/son.png", &ExpGetSoundChannelPitch)
        DECLARE_PARAMETER("expression", _("Canal"), false, "")
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("MusicChannelPitch", _("Pitch d'une musique"), _("Pitch d'une musique"), _("Musiques"), "res/actions/music.png", &ExpGetMusicChannelPitch)
        DECLARE_PARAMETER("expression", _("Canal"), false, "")
    DECLARE_END_EXPRESSION()
}

#if defined(GD_IDE_ONLY)
void AudioExtension::PrepareActionsResourcesForMerging(Instruction & action, ResourcesMergingHelper & resourcesMergingHelper)
{
    if ( action.GetType() == "PlaySound" || action.GetType() == "PlaySoundCanal" || action.GetType() == "PlayMusic" || action.GetType() == "PlayMusicCanal" )
        action.SetParameter( 0, resourcesMergingHelper.GetNewFilename(action.GetParameter(0).GetPlainString()));
}

void AudioExtension::GetPropertyForDebugger(RuntimeScene & scene, unsigned int propertyNb, std::string & name, std::string & value) const
{
    if ( propertyNb < SoundManager::GetInstance()->sounds.size() )
    {
        sf::Sound::Status soundStatus = SoundManager::GetInstance()->sounds[propertyNb]->GetStatus();

        if ( soundStatus == sf::Sound::Playing)
            name = _("Son jou� :");
        else if ( soundStatus == sf::Sound::Stopped)
            name = _("Son stopp� :");
        else if ( soundStatus == sf::Sound::Paused)
            name = _("Son en pause :");

        value = SoundManager::GetInstance()->sounds[propertyNb]->file;
    }
    if ( propertyNb-SoundManager::GetInstance()->sounds.size() < SoundManager::GetInstance()->musics.size() )
    {
        sf::Sound::Status soundStatus = SoundManager::GetInstance()->musics[propertyNb-SoundManager::GetInstance()->sounds.size()]->GetStatus();

        if ( soundStatus == sf::Sound::Playing)
            name = _("Musique jou�e :");
        else if ( soundStatus == sf::Sound::Stopped)
            name = _("Musique stopp�e :");
        else if ( soundStatus == sf::Sound::Paused)
            name = _("Musique en pause :");

        value = SoundManager::GetInstance()->musics[propertyNb-SoundManager::GetInstance()->sounds.size()]->file;
    }
}

bool AudioExtension::ChangeProperty(RuntimeScene & scene, unsigned int propertyNb, std::string newValue)
{
    return false;
}

unsigned int AudioExtension::GetNumberOfProperties(RuntimeScene & scene) const
{
    return SoundManager::GetInstance()->musics.size()+SoundManager::GetInstance()->sounds.size();
}

#endif

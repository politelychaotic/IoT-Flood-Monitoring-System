%Politely_Chaotic

Water_Level=[67;118;152;58;80;143;115;56;48;48;58;75;80;88;100;108;121;133;137;132;122;112;105;80;80;63;63;67;73;76;];

plot(Water_Level)
grid
%------- Send data to ThingSpeak -------
    for R = 1:length(Water_Level)
        thingSpeakWrite(ChannelID, Water_Level(R), 'WriteKey', 'WRITE_KEY_HERE')
        pause(15)
    end

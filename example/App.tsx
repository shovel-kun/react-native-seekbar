import React from 'react';
import {Text, View, StyleSheet, Button} from 'react-native';
import {Segment, Seekbar, SeekbarRef} from 'react-native-seekbar';

function App(): React.JSX.Element {
  const [position, setPosition] = React.useState(0);
  const [segment, setSegment] = React.useState<Segment | undefined>(undefined);
  const [isPlaying, setIsPlaying] = React.useState(false);

  const sliderRef = React.useRef<SeekbarRef>(null);

  const onValueChange = React.useCallback(
    (value: number) => {
      setPosition(value);
      // if (sliderRef.current) {
      //   sliderRef.current.position = value;
      // }
    },
    [setPosition],
  );

  const onValueChangeFinished = React.useCallback(() => {
    console.log('onValueChangeFinished');
  }, []);

  const onSegmentChange = React.useCallback(
    (segment: Segment) => {
      console.log('onSegmentChange', segment);
      setSegment(segment);
    },
    [setSegment],
  );

  // Memoize segments to prevent unnecessary re-renders
  const segments = React.useMemo(
    () => [
      {name: 'a', start: 0},
      {name: 'b', start: 3},
      {name: 'c', start: 6},
    ],
    [],
  );

  // Function to start rapid incrementing of position
  const startRapidIncrement = () => {
    setIsPlaying(true);
    const interval = setInterval(() => {
      setPosition(prevPosition => {
        if (prevPosition >= 10) {
          clearInterval(interval);
          setIsPlaying(false);
          return prevPosition;
        }
        // if (sliderRef.current) {
        //   sliderRef.current.position = position + 0.1; // Increment by 0.1 every 100ms
        // }
        return prevPosition + 0.1; // Increment by 0.1 every 100ms
      });
    }, 100); // Update every 100ms
  };

  return (
    <View style={styles.container}>
      <Text>Segment: {segment?.name}</Text>
      <Text>Position: {position.toFixed(2)}</Text>
      <Seekbar
        style={styles.view}
        position={position}
        duration={10}
        readAheadValue={3}
        onValueChange={{
          f: onValueChange,
        }}
        onValueChangeFinished={{
          f: onValueChangeFinished,
        }}
        onSegmentChange={{
          f: onSegmentChange,
        }}
        seekerColors={{
          thumbColor: 'red',
          progressColor: 'blue',
          trackColor: 'yellow',
          readAheadColor: 'green',
        }}
        segments={segments}
        hybridRef={{
          f: ref => {
            sliderRef.current = ref;
          },
        }}
      />
      <Button
        title={isPlaying ? 'Playing...' : 'Start Rapid Increment'}
        onPress={startRapidIncrement}
        disabled={isPlaying}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  view: {
    width: 300,
    height: 200,
  },
});

export default App;

import 'dart:io';
import 'dart:typed_data'; // Import for Uint8List
import 'package:flutter/material.dart';
import 'package:camera/camera.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Camera Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const CameraScreen(),
    );
  }
}

class CameraScreen extends StatefulWidget {
  const CameraScreen({Key? key}) : super(key: key);

  @override
  _CameraScreenState createState() => _CameraScreenState();
}

class _CameraScreenState extends State<CameraScreen> {
  CameraController? _controller;
  Future<void>? _initializeControllerFuture;
  List<Uint8List> _pictures = [];
  String _errorMessage = '';
  bool _isRetrying = false;

  @override
  void initState() {
    super.initState();
    _initializeCamera();
  }

  Future<void> _initializeCamera() async {
    setState(() {
      _isRetrying = true;
      _errorMessage = '';
    });

    try {
      final cameras = await availableCameras();
      if (cameras.isEmpty) {
        setState(() {
          _errorMessage = 'No cameras found on this device.';
          _isRetrying = false;
        });
        return;
      }

      final camera = cameras.first;
      final controller = CameraController(
        camera,
        ResolutionPreset.medium,
        enableAudio: false,
      );

      _initializeControllerFuture = controller.initialize();
      await _initializeControllerFuture;

      if (mounted) {
        setState(() {
          _controller = controller;
          _isRetrying = false;
        });
      }
    } on CameraException catch (e) {
      setState(() {
        _errorMessage = e.code == 'CameraAccessDenied'
            ? 'Camera access was denied. Please check your app permissions.'
            : 'Failed to initialize camera: ${e.description}';
        _isRetrying = false;
      });
    } catch (e) {
      setState(() {
        _errorMessage = 'Error initializing camera: ${e.toString()}';
        _isRetrying = false;
      });
    }
  }

  @override
  void dispose() {
    _controller?.dispose();
    super.dispose();
  }

  Future<void> _takePicture() async {
    if (_controller == null || !_controller!.value.isInitialized) {
      print('Error: Camera controller not initialized');
      return;
    }

    try {
      await _initializeControllerFuture;
      final XFile file = await _controller!.takePicture();

      // Read the image as bytes
      final Uint8List imageBytes = await file.readAsBytes();

      setState(() {
        _pictures.add(imageBytes);
      });

      // Optionally save the image to the gallery:
      // await GallerySaver.saveImage(file.path);

      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Picture taken and saved!')),
      );
    } catch (e) {
      print('Error taking picture: $e');
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Failed to take picture: ${e.toString()}')),
      );
    }
  }

  Widget _buildErrorWidget() {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Icon(Icons.error_outline, color: Colors.red, size: 60),
          SizedBox(height: 20),
          Text(
            _errorMessage,
            style: TextStyle(color: Colors.red, fontSize: 16),
            textAlign: TextAlign.center,
          ),
          SizedBox(height: 20),
          ElevatedButton(
            onPressed: _isRetrying ? null : _initializeCamera,
            child: Text(_isRetrying ? 'Retrying...' : 'Retry'),
          ),
        ],
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Camera App Demo'),
        backgroundColor: Colors.blue,
      ),
      body: Column(
        children: [
          Expanded(
            child: _errorMessage.isNotEmpty
                ? _buildErrorWidget()
                : _controller == null
                    ? Center(
                        child: CircularProgressIndicator(),
                      )
                    : FutureBuilder<void>(
                        future: _initializeControllerFuture,
                        builder: (context, snapshot) {
                          if (snapshot.connectionState == ConnectionState.done) {
                            return CameraPreview(_controller!);
                          } else {
                            return Center(
                              child: CircularProgressIndicator(),
                            );
                          }
                        },
                      ),
          ),
          if (_pictures.isNotEmpty)
            Container(
              height: MediaQuery.of(context).size.height * 0.4,
              child: GridView.builder(
                gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
                  crossAxisCount: 3,
                  crossAxisSpacing: 4,
                  mainAxisSpacing: 4,
                ),
                itemCount: _pictures.length,
                itemBuilder: (context, index) {
                  return Image.memory(
                    _pictures[index],
                    fit: BoxFit.cover,
                  );
                },
              ),
            ),
          Padding(
            padding: const EdgeInsets.all(16.0),
            child: ElevatedButton.icon(
              onPressed: _controller?.value.isInitialized == true
                  ? _takePicture
                  : null,
              icon: const Icon(Icons.camera_alt),
              label: const Text('Take Picture'),
            ),
          ),
        ],
      ),
    );
  }
}

pipeline {
    agent any

    tools {
        nodejs 'nodejs_v20.17.0'
    }

    stages {
        stage('Build') {
            steps {
                bat 'copy E:\\subbu\\subbu_project\\package.json .'
                bat 'call "%NODE_HOME%\\nodevars.bat"'
                bat 'npm run build'
            }
        }
    }
}

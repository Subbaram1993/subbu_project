pipeline {
    agent any

    tools {
        nodejs 'nodejs_v20.17.0'
    }

    stages {
        stage('Build') {
            steps {
                sh 'npm run build'
            }
        }
    }
}

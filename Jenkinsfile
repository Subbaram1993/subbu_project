pipeline {
    agent any

    tools {
        nodejs 'Node.js'
    }

    stages {
        stage('Clean and Build') {
            steps {
                deleteDir('node_modules') // Delete the node_modules directory
                sh 'npm run build'
            }
        }
    }
}
